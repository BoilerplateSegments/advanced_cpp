#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <variant>
#include <filesystem>
#include <span>

#define err(S) std::cerr << "Error:" << (S) << std::endl;
#define warr(S) std::cout << "[Warning] "<< (S) << std::endl;

#define DEBUG

namespace lisp {

    enum token_type {
        head,
        arg,
        none,
    };

    struct atom {
        std::string str; //remove str, its useless.
        token_type type = none;
        int ending = 0; //FIXME: optimize this out
        std::variant<std::monostate, std::string, int> content;

        atom() = default;;

        explicit atom(int x) {
            content = x;
        }

        explicit atom(std::string_view s) {
            str = s;

            if (str.ends_with(')')) {
                while (str.ends_with(')')) {
                    ending += 1;
                    str.pop_back();
                }
            }

            if (str.starts_with('(')) {
                content = str.erase(0, 1);
                type = lisp::head;
            } else {
                type = lisp::arg;
                if (str.starts_with('\"') && str.ends_with('\"')) {
                    content = (str.substr(1, str.size() - 2));
                } else { // In lisp, the none-head values are always some number
                    content = std::stoi(str);
                }
            }
        }

        [[nodiscard]] bool is_par_begin() const {
            return type == lisp::head;
        }

        [[nodiscard]] int get_ending_par() const {
            return ending;
        }

        [[nodiscard]] bool is_ending_par() const {
            return ending > 0;
        }

    };

    bool operator>>(std::istream &is, atom &s) {
        std::string t;
        is >> t;
        if (is.fail()) {
            return false;
        } else {
            s = atom(t);
            return true;
        }
    }

    std::ostream &operator<<(std::ostream &os, atom &a) {
        if (std::holds_alternative<int>(a.content)) {
            os << std::get<int>(a.content);
        } else {
            os << std::get<std::string>(a.content);
        }
        return os;
    }

    using tokenIter = std::vector<atom>::const_iterator;

    std::vector<atom> parse(std::span<atom> node, int depth) {
        // keep track of parens,
        // once a balance is reached, feed them to parse them again
        // invalidation -> reached the end but still no complete balance
        std::string head = std::get<std::string>(node.begin()->content);

#ifdef DEBUG
        for (const auto &t:node) {
            std::cout << "[parse" << depth << "] " << t.str << " ending->" << t.ending << " distance->"
                      << node.size() << " heading->" << head << std::endl;
        }
#endif
        std::vector<atom> result;
        std::vector<lisp::atom> args{};

        int par_count = depth;
        bool with_head_scope;

        if (node.begin()->is_par_begin()) {
            with_head_scope = true;
        } else {
            with_head_scope = false;
        }

        long sub_expr_begin=0;
        long sub_expr_end=0;

        if (with_head_scope) {
            //arg segmenting
            for (auto expr = node.begin(); expr != node.end(); expr++) {
                if (par_count == 0 && expr->is_par_begin()) {
                    par_count += 1;
                } else if (par_count ==1 && expr->is_par_begin()){
                    sub_expr_begin=expr-node.begin();
                } else if (expr->is_ending_par()) {
                    par_count -= expr->get_ending_par();
                    if (par_count == 0) {
                        for (const auto &sub:parse(node.subspan(sub_expr_begin+1,sub_expr_end-sub_expr_begin+2), depth + 1)) {
#ifdef DEBUG
                            std::cout<<"embrack "<<depth<<std::endl;
#endif
                            args.push_back(sub);
                        }
                        if(expr+1>=node.end()){
                            break;
                        } else {
                            parse(std::span<atom>(std::next(expr, 1), node.end()), depth);
                            break;
                        }
                    }
                }
            }
        } else {
            for (const auto &expr : node) {
#ifdef DEBUG

                std::cout<<"embrack "<<depth<<std::endl;
#endif
                result.emplace_back(expr);
            }
            return result;
        }

        if (head == "print") {
#ifdef DEBUG
            std::cout << "[arg size]" << args.size() << std::endl;
#endif
            for (const auto &x: args) {
                std::cout << std::get<std::string>(x.content);
            }
            std::cout << std::endl;
        } else if (head == "+") {
            int sum = 0;
            for (auto number: args) {
                sum += std::get<int>(number.content);
            }
            return std::vector<atom>{atom(sum)};
        } else {
            err("Encounter unknown function")
            exit(1);
        }

        // valid the pars are correct after the iter
        if (par_count != 0) {
            err("unbalanced s-expression");
        }

        return result;
    }
} // namespace lisp


std::vector<lisp::atom> tokenize(std::istream &i) {
    std::vector<lisp::atom> result;
    std::string t;
    while (i >> t) {
        result.emplace_back(lisp::atom(t));
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
    parse(std::span<lisp::atom>(tokens.begin(), tokens.end()), 0);
    return 0;
}
