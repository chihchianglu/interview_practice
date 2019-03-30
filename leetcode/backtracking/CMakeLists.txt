add_executable(additive-number
        additive-number.cpp
        )
add_custom_target(additive-number_run
        COMMAND additive-number
        )

add_executable(beautiful-arrangement
        beautiful-arrangement.cpp
        )
add_custom_target(beautiful-arrangement_run
        COMMAND beautiful-arrangement
        )

add_executable(combination-sum
        combination-sum.cpp
        )
add_custom_target(combination-sum_run
        COMMAND combination-sum
        )

add_executable(combination-sum-ii
        combination-sum-ii.cpp
        )
add_custom_target(combination-sum-ii_run
        COMMAND combination-sum-ii
        )

add_executable(combination-sum-iii
        combination-sum-iii.cpp
        )
add_custom_target(combination-sum-iii_run
        COMMAND combination-sum-iii
        )

add_executable(combination-sum-iv
        combination-sum-iv.cpp
        )
add_custom_target(combination-sum-iv_run
        COMMAND combination-sum-iv
        )

add_executable(combinations
        combinations.cpp
        )
add_custom_target(combinations_run
        COMMAND combinations
        )

add_executable(expression-add-operators
        expression-add-operators.cpp
        )
add_custom_target(expression-add-operators_run
        COMMAND expression-add-operators
        )

add_executable(generate-parentheses
        generate-parentheses.cpp
        )
add_custom_target(generate-parentheses_run
        COMMAND generate-parentheses
        )

add_executable(n-queens
        n-queens.cpp
        )
add_custom_target(n-queens_run
        COMMAND n-queens
        )

add_executable(n-queens-ii
        n-queens-ii.cpp
        )
add_custom_target(n-queens-ii_run
        COMMAND n-queens-ii
        )

add_executable(permutations
        permutations.cpp
        )
add_custom_target(permutations_run
        COMMAND permutations
        )

add_executable(permutations-ii
        permutations-ii.cpp
        )
add_custom_target(permutations-ii_run
        COMMAND permutations-ii
        )

add_executable(restore-ip-addresses
        restore-ip-addresses.cpp
        )
add_custom_target(restore-ip-addresses_run
        COMMAND restore-ip-addresses
        )

add_executable(subsets
        subsets.cpp
        )
add_custom_target(subsets_run
        COMMAND subsets
        )

add_executable(subsets-ii
        subsets-ii.cpp
        )
add_custom_target(subsets-ii_run
        COMMAND subsets-ii
        )

add_executable(sudoku-solver
        sudoku-solver.cpp
        )
add_custom_target(sudoku-solver_run
        COMMAND sudoku-solver
        )

add_executable(valid-sudoku
        valid-sudoku.cpp
        )
add_custom_target(valid-sudoku_run
        COMMAND valid-sudoku
        )

add_executable(word-search
        word-search.cpp
        )
add_custom_target(word-search_run
        COMMAND word-search
        )

add_executable(triggering_run_backtracking
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_backtracking
        additive-number_run
        beautiful-arrangement_run
        combination-sum_run
        combination-sum-ii_run
        combination-sum-iii_run
        combination-sum-iv_run
        combinations_run
        expression-add-operators_run
        generate-parentheses_run
        n-queens_run
        n-queens-ii_run
        permutations_run
        permutations-ii_run
        restore-ip-addresses_run
        subsets_run
        subsets-ii_run
        sudoku-solver_run
        valid-sudoku_run
        word-search_run
        )
