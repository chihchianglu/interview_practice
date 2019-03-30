add_executable(add-two-numbers
        add-two-numbers.cpp
        )
add_custom_target(add-two-numbers_run
        COMMAND add-two-numbers
        )

add_executable(add-two-numbers-ii
        add-two-numbers-ii.cpp
        )
add_custom_target(add-two-numbers-ii_run
        COMMAND add-two-numbers-ii
        )

add_executable(convert-sorted-list-to-bst
        convert-sorted-list-to-bst.cpp
        )
add_custom_target(convert-sorted-list-to-bst_run
        COMMAND convert-sorted-list-to-bst
        )

add_executable(copy-list-with-random-pointer
        copy-list-with-random-pointer.cpp
        )
add_custom_target(copy-list-with-random-pointer_run
        COMMAND copy-list-with-random-pointer
        )

add_executable(insert-into-a-cyclic-sorted-list
        insert-into-a-cyclic-sorted-list.cpp
        )
add_custom_target(insert-into-a-cyclic-sorted-list_run
        COMMAND insert-into-a-cyclic-sorted-list
        )

add_executable(insertion-sort-list
        insertion-sort-list.cpp
        )
add_custom_target(insertion-sort-list_run
        COMMAND insertion-sort-list
        )

add_executable(intersection-of-two-linked-lists
        intersection-of-two-linked-lists.cpp
        )
add_custom_target(intersection-of-two-linked-lists_run
        COMMAND intersection-of-two-linked-lists
        )

add_executable(linked-list-components
        linked-list-components.cpp
        )
add_custom_target(linked-list-components_run
        COMMAND linked-list-components
        )

add_executable(linked-list-cycle
        linked-list-cycle.cpp
        )
add_custom_target(linked-list-cycle_run
        COMMAND linked-list-cycle
        )

add_executable(linked-list-cycle-ii
        linked-list-cycle-ii.cpp
        )
add_custom_target(linked-list-cycle-ii_run
        COMMAND linked-list-cycle-ii
        )

add_executable(merge-2-sorted-lists
        merge-2-sorted-lists.cpp
        )
add_custom_target(merge-2-sorted-lists_run
        COMMAND merge-2-sorted-lists
        )

add_executable(merge-k-sorted-lists
        merge-k-sorted-lists.cpp
        )
add_custom_target(merge-k-sorted-lists_run
        COMMAND merge-k-sorted-lists
        )

add_executable(odd-even-linked-list
        odd-even-linked-list.cpp
        )
add_custom_target(odd-even-linked-list_run
        COMMAND odd-even-linked-list
        )

add_executable(palindrome-linked-list
        palindrome-linked-list.cpp
        )
add_custom_target(palindrome-linked-list_run
        COMMAND palindrome-linked-list
        )

add_executable(partition-list
        partition-list.cpp
        )
add_custom_target(partition-list_run
        COMMAND partition-list
        )

add_executable(plus-one-linked-list
        plus-one-linked-list.cpp
        )
add_custom_target(plus-one-linked-list_run
        COMMAND plus-one-linked-list
        )

add_executable(remove-duplicates-from-sorted-list
        remove-duplicates-from-sorted-list.cpp
        )
add_custom_target(remove-duplicates-from-sorted-list_run
        COMMAND remove-duplicates-from-sorted-list
        )

add_executable(remove-duplicates-from-sorted-list-ii
        remove-duplicates-from-sorted-list-ii.cpp
        )
add_custom_target(remove-duplicates-from-sorted-list-ii_run
        COMMAND remove-duplicates-from-sorted-list-ii
        )

add_executable(remove-linked-list-elements
        remove-linked-list-elements.cpp
        )
add_custom_target(remove-linked-list-elements_run
        COMMAND remove-linked-list-elements
        )

add_executable(remove-nth-node-from-end-of-list
        remove-nth-node-from-end-of-list.cpp
        )
add_custom_target(remove-nth-node-from-end-of-list_run
        COMMAND remove-nth-node-from-end-of-list
        )

add_executable(reorder-list
        reorder-list.cpp
        )
add_custom_target(reorder-list_run
        COMMAND reorder-list
        )

add_executable(reverse-linked-list
        reverse-linked-list.cpp
        )
add_custom_target(reverse-linked-list_run
        COMMAND reverse-linked-list
        )

add_executable(rotate-list
        rotate-list.cpp
        )
add_custom_target(rotate-list_run
        COMMAND rotate-list
        )

add_executable(split-linked-list-in-parts
        split-linked-list-in-parts.cpp
        )
add_custom_target(split-linked-list-in-parts_run
        COMMAND split-linked-list-in-parts
        )

add_executable(swap-nodes-in-pairs
        swap-nodes-in-pairs.cpp
        )
add_custom_target(swap-nodes-in-pairs_run
        COMMAND swap-nodes-in-pairs
        )

add_executable(triggering_run_linked_list
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_linked_list
        add-two-numbers_run
        add-two-numbers-ii_run
        convert-sorted-list-to-bst_run
        copy-list-with-random-pointer_run
        insert-into-a-cyclic-sorted-list_run
        insertion-sort-list_run
        intersection-of-two-linked-lists_run
        linked-list-components_run
        linked-list-cycle_run
        linked-list-cycle-ii_run
        merge-2-sorted-lists_run
        merge-k-sorted-lists_run
        odd-even-linked-list_run
        palindrome-linked-list_run
        partition-list_run
        plus-one-linked-list_run
        remove-duplicates-from-sorted-list_run
        remove-duplicates-from-sorted-list-ii_run
        remove-linked-list-elements_run
        remove-nth-node-from-end-of-list_run
        reorder-list_run
        reverse-linked-list_run
        rotate-list_run
        split-linked-list-in-parts_run
        swap-nodes-in-pairs_run
        )
