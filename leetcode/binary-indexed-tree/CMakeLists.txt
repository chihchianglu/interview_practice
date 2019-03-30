add_executable(count-of-smaller-numbers-after-self
        count-of-smaller-numbers-after-self.cpp
        )
add_custom_target(count-of-smaller-numbers-after-self_run
        COMMAND count-of-smaller-numbers-after-self
        )

add_executable(triggering_run_bit
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_bit
        count-of-smaller-numbers-after-self_run
        )
