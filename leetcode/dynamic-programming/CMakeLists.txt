add_executable(01-matrix
        01-matrix.cpp
        )
add_custom_target(01-matrix_run
        COMMAND 01-matrix
        )

add_executable(2-keys-keyboard
        2-keys-keyboard.cpp
        )
add_custom_target(2-keys-keyboard_run
        COMMAND 2-keys-keyboard
        )

add_executable(4-keys-keyboard
        4-keys-keyboard.cpp
        )
add_custom_target(4-keys-keyboard_run
        COMMAND 4-keys-keyboard
        )

add_executable(best-time-to-buy-and-sell-stock
        best-time-to-buy-and-sell-stock.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock_run
        COMMAND best-time-to-buy-and-sell-stock
        )

add_executable(best-time-to-buy-and-sell-stock-ii
        best-time-to-buy-and-sell-stock-ii.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock-ii_run
        COMMAND best-time-to-buy-and-sell-stock-ii
        )

add_executable(best-time-to-buy-and-sell-stock-iii
        best-time-to-buy-and-sell-stock-iii.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock-iii_run
        COMMAND best-time-to-buy-and-sell-stock-iii
        )

add_executable(best-time-to-buy-and-sell-stock-iv
        best-time-to-buy-and-sell-stock-iv.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock-iv_run
        COMMAND best-time-to-buy-and-sell-stock-iv
        )

add_executable(best-time-to-buy-and-sell-stock-with-cooldown
        best-time-to-buy-and-sell-stock-with-cooldown.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock-with-cooldown_run
        COMMAND best-time-to-buy-and-sell-stock-with-cooldown
        )

add_executable(best-time-to-buy-and-sell-stock-with-transaction-fee
        best-time-to-buy-and-sell-stock-with-transaction-fee.cpp
        )
add_custom_target(best-time-to-buy-and-sell-stock-with-transaction-fee_run
        COMMAND best-time-to-buy-and-sell-stock-with-transaction-fee
        )

add_executable(climbing-stairs
        climbing-stairs.cpp
        )
add_custom_target(climbing-stairs_run
        COMMAND climbing-stairs
        )

add_executable(coin-change
        coin-change.cpp
        )
add_custom_target(coin-change_run
        COMMAND coin-change
        )

add_executable(decode-ways
        decode-ways.cpp
        )
add_custom_target(decode-ways_run
        COMMAND decode-ways
        )

add_executable(gas-station-iii
        gas-station-iii.cpp
        )
add_custom_target(gas-station-iii_run
        COMMAND gas-station-iii
        )

add_executable(house-robber
        house-robber.cpp
        )
add_custom_target(house-robber_run
        COMMAND house-robber
        )

add_executable(house-robber-ii
        house-robber-ii.cpp
        )
add_custom_target(house-robber-ii_run
        COMMAND house-robber-ii
        )

add_executable(longest-continuous-increasing-subsequence
        longest-continuous-increasing-subsequence.cpp
        )
add_custom_target(longest-continuous-increasing-subsequence_run
        COMMAND longest-continuous-increasing-subsequence
        )

add_executable(longest-increasing-subsequence
        longest-increasing-subsequence.cpp
        )
add_custom_target(longest-increasing-subsequence_run
        COMMAND longest-increasing-subsequence
        )

add_executable(longest-line-of-consecutive-one-in-matrix
        longest-line-of-consecutive-one-in-matrix.cpp
        )
add_custom_target(longest-line-of-consecutive-one-in-matrix_run
        COMMAND longest-line-of-consecutive-one-in-matrix
        )

add_executable(longest-palindromic-subsequence
        longest-palindromic-subsequence.cpp
        )
add_custom_target(longest-palindromic-subsequence_run
        COMMAND longest-palindromic-subsequence
        )

add_executable(longest-palindromic-substring
        longest-palindromic-substring.cpp
        )
add_custom_target(longest-palindromic-substring_run
        COMMAND longest-palindromic-substring
        )

add_executable(paint-fence
        paint-fence.cpp
        )
add_custom_target(paint-fence_run
        COMMAND paint-fence
        )

add_executable(paint-house
        paint-house.cpp
        )
add_custom_target(paint-house_run
        COMMAND paint-house
        )

add_executable(palindromic-substrings
        palindromic-substrings.cpp
        )
add_custom_target(palindromic-substrings_run
        COMMAND palindromic-substrings
        )

add_executable(partition-equal-subset-sum
        partition-equal-subset-sum.cpp
        )
add_custom_target(partition-equal-subset-sum_run
        COMMAND partition-equal-subset-sum
        )

add_executable(perfect-squares
        perfect-squares.cpp
        )
add_custom_target(perfect-squares_run
        COMMAND perfect-squares
        )

add_executable(target-sum
        target-sum.cpp
        )
add_custom_target(target-sum_run
        COMMAND target-sum
        )

add_executable(triangle
        triangle.cpp
        )
add_custom_target(triangle_run
        COMMAND triangle
        )

add_executable(ugly-number
        ugly-number.cpp
        )
add_custom_target(ugly-number_run
        COMMAND ugly-number
        )

add_executable(ugly-number-ii
        ugly-number-ii.cpp
        )
add_custom_target(ugly-number-ii_run
        COMMAND ugly-number-ii
        )

add_executable(unique-paths
        unique-paths.cpp
        )
add_custom_target(unique-paths_run
        COMMAND unique-paths
        )

add_executable(unique-paths-ii
        unique-paths-ii.cpp
        )
add_custom_target(unique-paths-ii_run
        COMMAND unique-paths-ii
        )

add_executable(word-break
        word-break.cpp
        )
add_custom_target(word-break_run
        COMMAND word-break
        )

add_executable(triggering_run_dp
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_dp
        01-matrix_run
        2-keys-keyboard_run
        4-keys-keyboard_run
        best-time-to-buy-and-sell-stock_run
        best-time-to-buy-and-sell-stock-ii_run
        best-time-to-buy-and-sell-stock-iii_run
        best-time-to-buy-and-sell-stock-iv_run
        best-time-to-buy-and-sell-stock-with-cooldown_run
        best-time-to-buy-and-sell-stock-with-transaction-fee_run
        climbing-stairs_run
        coin-change_run
        decode-ways_run
        gas-station-iii_run
        house-robber_run
        house-robber-ii_run
        longest-continuous-increasing-subsequence_run
        longest-increasing-subsequence_run
        longest-line-of-consecutive-one-in-matrix_run
        longest-palindromic-subsequence_run
        longest-palindromic-substring_run
        paint-fence_run
        paint-house_run
        palindromic-substrings_run
        partition-equal-subset-sum_run
        perfect-squares_run
        target-sum_run
        triangle_run
        ugly-number_run
        ugly-number-ii_run
        unique-paths_run
        unique-paths-ii_run
        word-break_run
        )
