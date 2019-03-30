add_executable(candy
        candy.cpp
        )
add_custom_target(candy_run
        COMMAND candy
        )

add_executable(find-permutation
        find-permutation.cpp
        )
add_custom_target(find-permutation_run
        COMMAND find-permutation
        )

add_executable(gas-station
        gas-station.cpp
        )
add_custom_target(gas-station_run
        COMMAND gas-station
        )

add_executable(gas-station-ii
        gas-station-ii.cpp
        )
add_custom_target(gas-station-ii_run
        COMMAND gas-station-ii
        )

add_executable(jump-game
        jump-game.cpp
        )
add_custom_target(jump-game_run
        COMMAND jump-game
        )

add_executable(jump-game-ii
        jump-game-ii.cpp
        )
add_custom_target(jump-game-ii_run
        COMMAND jump-game-ii
        )

add_executable(meeting-rooms
        meeting-rooms.cpp
        )
add_custom_target(meeting-rooms_run
        COMMAND meeting-rooms
        )

add_executable(meeting-rooms-ii
        meeting-rooms-ii.cpp
        )
add_custom_target(meeting-rooms-ii_run
        COMMAND meeting-rooms-ii
        )

add_executable(minimum-cost-to-hire-k-workers
        minimum-cost-to-hire-k-workers.cpp
        )
add_custom_target(minimum-cost-to-hire-k-workers_run
        COMMAND minimum-cost-to-hire-k-workers
        )

add_executable(minimum-number-of-arrows-to-burst-balloons
        minimum-number-of-arrows-to-burst-balloons.cpp
        )
add_custom_target(minimum-number-of-arrows-to-burst-balloons_run
        COMMAND minimum-number-of-arrows-to-burst-balloons
        )

add_executable(non-overlapping-intervals
        non-overlapping-intervals.cpp
        )
add_custom_target(non-overlapping-intervals_run
        COMMAND non-overlapping-intervals
        )

add_executable(queue-reconstruction-by-height
        queue-reconstruction-by-height.cpp
        )
add_custom_target(queue-reconstruction-by-height_run
        COMMAND queue-reconstruction-by-height
        )

add_executable(remove-duplicate-letters
        remove-duplicate-letters.cpp
        )
add_custom_target(remove-duplicate-letters_run
        COMMAND remove-duplicate-letters
        )

add_executable(task-scheduler
        task-scheduler.cpp
        )
add_custom_target(task-scheduler_run
        COMMAND task-scheduler
        )

add_executable(triggering_run_greedy
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_greedy
        candy_run
        find-permutation_run
        gas-station_run
        gas-station-ii_run
        jump-game_run
        jump-game-ii_run
        meeting-rooms_run
        meeting-rooms-ii_run
        minimum-cost-to-hire-k-workers_run
        minimum-number-of-arrows-to-burst-balloons_run
        non-overlapping-intervals_run
        queue-reconstruction-by-height_run
        remove-duplicate-letters_run
        task-scheduler_run
        )
