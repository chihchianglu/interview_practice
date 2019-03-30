add_executable(add-binary
        add-binary.cpp
        )
add_custom_target(add-binary_run
        COMMAND add-binary
        )

add_executable(add-bold-tag-in-string
        add-bold-tag-in-string.cpp
        )
add_custom_target(add-bold-tag-in-string_run
        COMMAND add-bold-tag-in-string
        )

add_executable(add-strings
        add-strings.cpp
        )
add_custom_target(add-strings_run
        COMMAND add-strings
        )

add_executable(bulls-and-cows
        bulls-and-cows.cpp
        )
add_custom_target(bulls-and-cows_run
        COMMAND bulls-and-cows
        )

add_executable(compare-version-numbers
        compare-version-numbers.cpp
        )
add_custom_target(compare-version-numbers_run
        COMMAND compare-version-numbers
        )

add_executable(count-and-say
        count-and-say.cpp
        )
add_custom_target(count-and-say_run
        COMMAND count-and-say
        )

add_executable(find-all-anagrams-in-a-string
        find-all-anagrams-in-a-string.cpp
        )
add_custom_target(find-all-anagrams-in-a-string_run
        COMMAND find-all-anagrams-in-a-string
        )

add_executable(find-the-difference
        find-the-difference.cpp
        )
add_custom_target(find-the-difference_run
        COMMAND find-the-difference
        )

add_executable(first-unique-character-in-a-string
        first-unique-character-in-a-string.cpp
        )
add_custom_target(first-unique-character-in-a-string_run
        COMMAND first-unique-character-in-a-string
        )

add_executable(group-anagrams
        group-anagrams.cpp
        )
add_custom_target(group-anagrams_run
        COMMAND group-anagrams
        )

add_executable(implement-strstr
        implement-strstr.cpp
        )
add_custom_target(implement-strstr_run
        COMMAND implement-strstr
        )

add_executable(isomorphic-strings
        isomorphic-strings.cpp
        )
add_custom_target(isomorphic-strings_run
        COMMAND isomorphic-strings
        )

add_executable(longest-substring-with-at-most-k-distinct-characters
        longest-substring-with-at-most-k-distinct-characters.cpp
        )
add_custom_target(longest-substring-with-at-most-k-distinct-characters_run
        COMMAND longest-substring-with-at-most-k-distinct-characters
        )

add_executable(longest-substring-without-repeating-characters
        longest-substring-without-repeating-characters.cpp
        )
add_custom_target(longest-substring-without-repeating-characters_run
        COMMAND longest-substring-without-repeating-characters
        )

add_executable(longest-valid-parentheses
        longest-valid-parentheses.cpp
        )
add_custom_target(longest-valid-parentheses_run
        COMMAND longest-valid-parentheses
        )

add_executable(multiply-strings
        multiply-strings.cpp
        )
add_custom_target(multiply-strings_run
        COMMAND multiply-strings
        )

add_executable(one-edit-distance
        one-edit-distance.cpp
        )
add_custom_target(one-edit-distance_run
        COMMAND one-edit-distance
        )

add_executable(valid-palindrome
        valid-palindrome.cpp
        )
add_custom_target(valid-palindrome_run
        COMMAND valid-palindrome
        )

add_executable(valid-palindrome-ii
        valid-palindrome-ii.cpp
        )
add_custom_target(valid-palindrome-ii_run
        COMMAND valid-palindrome-ii
        )

add_executable(valid-parentheses
        valid-parentheses.cpp
        )
add_custom_target(valid-parentheses_run
        COMMAND valid-parentheses
        )

add_executable(valid-word-abbreviation
        valid-word-abbreviation.cpp
        )
add_custom_target(valid-word-abbreviation_run
        COMMAND valid-word-abbreviation
        )

add_executable(valid-word-square
        valid-word-square.cpp
        )
add_custom_target(valid-word-square_run
        COMMAND valid-word-square
        )

add_executable(triggering_run_string
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_string
        add-binary_run
        add-bold-tag-in-string_run
        add-strings_run
        bulls-and-cows_run
        compare-version-numbers_run
        count-and-say_run
        find-all-anagrams-in-a-string_run
        find-the-difference_run
        first-unique-character-in-a-string_run
        group-anagrams_run
        implement-strstr_run
        isomorphic-strings_run
        longest-substring-with-at-most-k-distinct-characters_run
        longest-substring-without-repeating-characters_run
        longest-valid-parentheses_run
        multiply-strings_run
        one-edit-distance_run
        valid-palindrome_run
        valid-palindrome-ii_run
        valid-parentheses_run
        valid-word-abbreviation_run
        valid-word-square_run
        )
