add_executable(linked-list-random-node
        linked-list-random-node.cpp
        )
add_custom_target(linked-list-random-node_run
        COMMAND linked-list-random-node
        )

add_executable(random-pick-index
        random-pick-index.cpp
        )
add_custom_target(random-pick-index_run
        COMMAND random-pick-index
        )

add_executable(random-pick-with-weight
        random-pick-with-weight.cpp
        )
add_custom_target(random-pick-with-weight_run
        COMMAND random-pick-with-weight
        )

add_executable(reservoir-sampling
        reservoir-sampling.cpp
        )
add_custom_target(reservoir-sampling_run
        COMMAND reservoir-sampling
        )

add_executable(select-a-random-number-from-stream
        select-a-random-number-from-stream.cpp
        )
add_custom_target(select-a-random-number-from-stream_run
        COMMAND select-a-random-number-from-stream
        )

add_executable(triggering_run_sampling
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_sampling
        linked-list-random-node_run
        random-pick-index_run
        random-pick-with-weight_run
        reservoir-sampling_run
        select-a-random-number-from-stream_run
        )
