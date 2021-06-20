# case sensitive
set(hello "hello")
set(WORLD "world!")
message(">${hello} ${WORLD}!")

#swap
function(swap var1 var2)
    # double bracket trick
    # ${var1} -> get the name of actual arg -> x
    # ${${var1}} -> unwrap the x and get the content
    set(_TEMP "${${var1}}")
    set(${var1} "${${var2}}" PARENT_SCOPE)
    set(${var2} "${_TEMP}" PARENT_SCOPE)
endfunction(swap)

set(x 123)
set(y "asd")
message("x -> ${x} y-> ${y}")
swap(x y)
message("x -> ${x} y-> ${y}")

#object?
set(CAT_NAME "alex")
set(CAT_AGE 3)
set(ANIMAL "CAT")
message("${${ANIMAL}_NAME} is age ${${ANIMAL}_AGE}")

#arithmetic
math(EXPR slbari "1+2*3")
message(${slbari}) # -> 2

#extra help
execute_process(COMMAND bash "-c" "bc -l <<<'1+1'")

# Lists == Semicolon-delimited strings :)
# <https://cmake.org/cmake/help/latest/command/list.html>
set(SLB_LST "ABC;DEF;HJK")
message("${SLB_LST}")
list(REMOVE_ITEM SLB_LST "DEF")
message("${SLB_LST}")

list(FIND SLB_LST "HJK" o1)
list(FIND SLB_LST "NO" o2)
message("${o1}") # true  ->  1
message("${o2}") # false -> -1

# Every Statement is a Command 
# There is no return value!
list(LENGTH SLB_LST slb_len)
message("List length -> ${slb_len}")

foreach(ARG ${SLB_LST})
    message("For each -> ${ARG}")
endforeach()
