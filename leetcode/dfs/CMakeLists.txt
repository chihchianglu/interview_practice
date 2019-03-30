add_executable(decode-string
        decode-string.cpp
        )
add_custom_target(decode-string_run
        COMMAND decode-string
        )

add_executable(nested-list-weight-sum
        nested-list-weight-sum.cpp
        )
add_custom_target(nested-list-weight-sum_run
        COMMAND nested-list-weight-sum
        )

add_executable(nested-list-weight-sum-ii
        nested-list-weight-sum-ii.cpp
        )
add_custom_target(nested-list-weight-sum-ii_run
        COMMAND nested-list-weight-sum-ii
        )

add_executable(triggering_run_dfs
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_dfs
        decode-string_run
        nested-list-weight-sum_run
        nested-list-weight-sum-ii_run
        )
