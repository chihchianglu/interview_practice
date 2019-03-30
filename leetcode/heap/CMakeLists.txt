add_executable(employee-free-time
        employee-free-time.cpp
        )
add_custom_target(employee-free-time_run
        COMMAND employee-free-time
        )

add_executable(find-median-from-data-stream
        find-median-from-data-stream.cpp
        )
add_custom_target(find-median-from-data-stream_run
        COMMAND find-median-from-data-stream
        )

add_executable(kth-largest-element-in-a-stream
        kth-largest-element-in-a-stream.cpp
        )
add_custom_target(kth-largest-element-in-a-stream_run
        COMMAND kth-largest-element-in-a-stream
        )

add_executable(kth-smallest-element-in-a-sorted-matrix
        kth-smallest-element-in-a-sorted-matrix.cpp
        )
add_custom_target(kth-smallest-element-in-a-sorted-matrix_run
        COMMAND kth-smallest-element-in-a-sorted-matrix
        )

add_executable(triggering_run_heap
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_heap
        employee-free-time_run
        find-median-from-data-stream_run
        kth-largest-element-in-a-stream_run
        kth-smallest-element-in-a-sorted-matrix_run
        )
