add_executable(insertion-sort
        insertion-sort.cpp
        )
add_custom_target(insertion-sort_run
        COMMAND insertion-sort
        )

add_executable(heap-sort
        heap-sort.cpp
        )
add_custom_target(heap-sort_run
        COMMAND heap-sort
        )

add_executable(merge-sort
        merge-sort.cpp
        )
add_custom_target(merge-sort_run
        COMMAND merge-sort
        )

add_executable(quick-sort
        quick-sort.cpp
        )
add_custom_target(quick-sort_run
        COMMAND quick-sort
        )

add_executable(triggering_run_sort
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_sort
        insertion-sort_run
        heap-sort_run
        merge-sort_run
        quick-sort_run
        )
