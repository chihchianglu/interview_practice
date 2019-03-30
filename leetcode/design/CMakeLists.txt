add_executable(design-compressed-string-iterator
        design-compressed-string-iterator.cpp
        )
add_custom_target(design-compressed-string-iterator_run
        COMMAND design-compressed-string-iterator
        )

add_executable(design-hit-counter
        design-hit-counter.cpp
        )
add_custom_target(design-hit-counter_run
        COMMAND design-hit-counter
        )

add_executable(design-phone-directory
        design-phone-directory.cpp
        )
add_custom_target(design-phone-directory_run
        COMMAND design-phone-directory
        )

add_executable(design-tic-tac-toe
        design-tic-tac-toe.cpp
        )
add_custom_target(design-tic-tac-toe_run
        COMMAND design-tic-tac-toe
        )

add_executable(encode-and-decode-tinyurl
        encode-and-decode-tinyurl.cpp
        )
add_custom_target(encode-and-decode-tinyurl_run
        COMMAND encode-and-decode-tinyurl
        )

add_executable(exam-room
        exam-room.cpp
        )
add_custom_target(exam-room_run
        COMMAND exam-room
        )

add_executable(flatten-2d-vector
        flatten-2d-vector.cpp
        )
add_custom_target(flatten-2d-vector_run
        COMMAND flatten-2d-vector
        )

add_executable(implement-queue-using-fixed-size-array
        implement-queue-using-fixed-size-array.cpp
        )
add_custom_target(implement-queue-using-fixed-size-array_run
        COMMAND implement-queue-using-fixed-size-array
        )

add_executable(insert-delete-getrandom-o1
        insert-delete-getrandom-o1.cpp
        )
add_custom_target(insert-delete-getrandom-o1_run
        COMMAND insert-delete-getrandom-o1
        )

add_executable(insert-delete-getrandom-o1-duplicates-allowed
        insert-delete-getrandom-o1-duplicates-allowed.cpp
        )
add_custom_target(insert-delete-getrandom-o1-duplicates-allowed_run
        COMMAND insert-delete-getrandom-o1-duplicates-allowed
        )

add_executable(lfu-cache
        lfu-cache.cpp
        )
add_custom_target(lfu-cache_run
        COMMAND lfu-cache
        )

add_executable(logger-rate-limiter
        logger-rate-limiter.cpp
        )
add_custom_target(logger-rate-limiter_run
        COMMAND logger-rate-limiter
        )

add_executable(lru-cache
        lru-cache.cpp
        )
add_custom_target(lru-cache_run
        COMMAND lru-cache
        )

add_executable(moving-average-from-data-stream
        moving-average-from-data-stream.cpp
        )
add_custom_target(moving-average-from-data-stream_run
        COMMAND moving-average-from-data-stream
        )

add_executable(my-calendar-i
        my-calendar-i.cpp
        )
add_custom_target(my-calendar-i_run
        COMMAND my-calendar-i
        )

add_executable(my-calendar-ii
        my-calendar-ii.cpp
        )
add_custom_target(my-calendar-ii_run
        COMMAND my-calendar-ii
        )

add_executable(read-n-characters-given-read4
        read-n-characters-given-read4.cpp
        )
add_custom_target(read-n-characters-given-read4_run
        COMMAND read-n-characters-given-read4
        )

add_executable(read-n-characters-given-read4-ii-call-multiple-times
        read-n-characters-given-read4-ii-call-multiple-times.cpp
        )
add_custom_target(read-n-characters-given-read4-ii-call-multiple-times_run
        COMMAND read-n-characters-given-read4-ii-call-multiple-times
        )

add_executable(shortest-word-distance-ii
        shortest-word-distance-ii.cpp
        )
add_custom_target(shortest-word-distance-ii_run
        COMMAND shortest-word-distance-ii
        )

add_executable(shuffle-an-array
        shuffle-an-array.cpp
        )
add_custom_target(shuffle-an-array_run
        COMMAND shuffle-an-array
        )

add_executable(triggering_run_design
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_design
        design-compressed-string-iterator_run
        design-hit-counter_run
        design-phone-directory_run
        design-tic-tac-toe_run
        encode-and-decode-tinyurl_run
        exam-room_run
        flatten-2d-vector_run
        implement-queue-using-fixed-size-array_run
        insert-delete-getrandom-o1_run
        insert-delete-getrandom-o1-duplicates-allowed_run
        lfu-cache_run
        logger-rate-limiter_run
        lru-cache_run
        moving-average-from-data-stream_run
        my-calendar-i_run
        my-calendar-ii_run
        read-n-characters-given-read4_run
        read-n-characters-given-read4-ii-call-multiple-times_run
        shortest-word-distance-ii_run
        shuffle-an-array_run
        )
