add_executable(different-ways-to-add-parentheses
        different-ways-to-add-parentheses.cpp
        )
add_custom_target(different-ways-to-add-parentheses_run
        COMMAND different-ways-to-add-parentheses
        )

add_executable(the-skyline-problem
        the-skyline-problem.cpp
        )
add_custom_target(the-skyline-problem_run
        COMMAND the-skyline-problem
        )

add_executable(triggering_run_dnc
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_dnc
        different-ways-to-add-parentheses_run
        the-skyline-problem_run
        )
