#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <variant>
#include <filesystem>

#define err(S) std::cerr << "Error:" << (S) << std::endl;

namespace lisp {

    enum token_type {
        head,
        arg,
        none,
    };

    struct token {
        std::string str;
        token_type type = none;
        bool end_q = false;

        token() = default;;

        explicit token(std::string_view s) {
            str = s;
            if (str.starts_with('(')) {
                str.erase(0, 1);
                type = lisp::head;
            } else {
                type = lisp::arg;
            }

            if (str.ends_with(')')) {
                str.pop_back();
                end_q = true;
            }
        }

        [[nodiscard]] bool is_par_begin() const {
            return type == lisp::head;
        }

        [[nodiscard]] bool is_par_end() const {
            return end_q;
        }
    };

    // data types
    struct atom {
        std::variant<std::string, int> content;

        explicit atom(const lisp::token &t) {
            if (t.str.starts_with('\"') && t.str.ends_with('\"')) {
                content = t.str.substr(1, t.str.size() - 2);
            }
        }
    };

    bool operator>>(std::istream &is, lisp::token &s) {
        std::string t;
        is >> t;
        if (is.fail()) {
            return false;
        } else {
            s = token(t);
            return true;
        }
    }

    std::ostream &operator<<(std::ostream &os, lisp::atom &a) {
        os << std::get<std::string>(a.content);
        return os;
    }

    using tokenIter = std::vector<lisp::token>::const_iterator;

    // TODO: return value should be a polymorphic value
    void eval(tokenIter begin, tokenIter end) {
        std::vector<lisp::atom> args{};
        auto head = begin->str;
        std::for_each(begin + 1, end, [&](const lisp::token &e) {
            args.emplace_back(e);
        });

        if (head == "print") {
            for (auto x: args) {
                std::cout << x;
            }
            std::cout << std::endl;
        } else {
            err("Encounter unknown function")
            exit(1);
        }
    }

    void parse(const std::vector<lisp::token> &t) {
        // keep track of parens,
        // once a balance is reached, feed them to eval
        // invalidation -> reached the end but still no complete balance

        int par_count = 0;
        tokenIter begin;
        tokenIter end;

        for (auto x = t.begin(); x != t.end(); x++) {
            if (x->is_par_begin()) {
                if (par_count == 0) begin = x;
                par_count += 1;
            } else if (x->is_par_end()) {
                par_count -= 1;
                if (par_count == 0) {
                    end = x;
                    eval(begin, end + 1);
                }
            }
        }

        if (par_count != 0) {
            err("unbalanced s-expression")
        }
    }
} // namespace lisp

std::vector<lisp::token> tokenize(std::istream &i) {
    std::vector<lisp::token> result;
    lisp::token t;
    while (i >> t) {
        result.emplace_back(t);
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc == 1) {
        err(" Usage: spike [file] ...")
        exit(1);
    }

    if (!std::filesystem::exists(argv[1])) {
        err("File doesn't exist")
        exit(1);
    }

    std::ifstream fileStream(argv[1]);


    if (fileStream.fail()) {
        err("Cannot open source file")
        exit(1);
    }
    auto tokens = tokenize(fileStream);
    parse(tokens);
    return 0;
}
