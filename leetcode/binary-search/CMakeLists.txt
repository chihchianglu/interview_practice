add_executable(divide-two-integers
        divide-two-integers.cpp
        )
add_custom_target(divide-two-integers_run
        COMMAND divide-two-integers
        )

add_executable(find-first-and-last-position-of-element-in-sorted-array
        find-first-and-last-position-of-element-in-sorted-array.cpp
        )
add_custom_target(find-first-and-last-position-of-element-in-sorted-array_run
        COMMAND find-first-and-last-position-of-element-in-sorted-array
        )

add_executable(powerx-n
        powerx-n.cpp
        )
add_custom_target(powerx-n_run
        COMMAND powerx-n
        )

add_executable(search-in-rotated-sorted-array
        search-in-rotated-sorted-array.cpp
        )
add_custom_target(search-in-rotated-sorted-array_run
        COMMAND search-in-rotated-sorted-array
        )

add_executable(search-in-rotated-sorted-array-ii
        search-in-rotated-sorted-array-ii.cpp
        )
add_custom_target(search-in-rotated-sorted-array-ii_run
        COMMAND search-in-rotated-sorted-array-ii
        )

add_executable(search-insert-position
        search-insert-position.cpp
        )
add_custom_target(search-insert-position_run
        COMMAND search-insert-position
        )

add_executable(sqrt
        sqrt.cpp
        )
add_custom_target(sqrt_run
        COMMAND sqrt
        )

add_executable(valid-perfect-square
        valid-perfect-square.cpp
        )
add_custom_target(valid-perfect-square_run
        COMMAND valid-perfect-square
        )

add_executable(triggering_run_bs
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_bs
        divide-two-integers_run
        find-first-and-last-position-of-element-in-sorted-array_run
        powerx-n_run
        search-in-rotated-sorted-array_run
        search-in-rotated-sorted-array-ii_run
        search-insert-position_run
        sqrt_run
        valid-perfect-square_run
        )
