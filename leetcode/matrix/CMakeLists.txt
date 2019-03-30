add_executable(brick-wall
        brick-wall.cpp
        )
add_custom_target(brick-wall_run
        COMMAND brick-wall
        )

add_executable(diagonal-traverse
        diagonal-traverse.cpp
        )
add_custom_target(diagonal-traverse_run
        COMMAND diagonal-traverse
        )

add_executable(escape-the-ghosts
        escape-the-ghosts.cpp
        )
add_custom_target(escape-the-ghosts_run
        COMMAND escape-the-ghosts
        )

add_executable(island-perimeter
        island-perimeter.cpp
        )
add_custom_target(island-perimeter_run
        COMMAND island-perimeter
        )

add_executable(lonely-pixel-i
        lonely-pixel-i.cpp
        )
add_custom_target(lonely-pixel-i_run
        COMMAND lonely-pixel-i
        )

add_executable(lonely-pixel-ii
        lonely-pixel-ii.cpp
        )
add_custom_target(lonely-pixel-ii_run
        COMMAND lonely-pixel-ii
        )

add_executable(number-of-corner-rectangles
        number-of-corner-rectangles.cpp
        )
add_custom_target(number-of-corner-rectangles_run
        COMMAND number-of-corner-rectangles
        )

add_executable(rotate-image
        rotate-image.cpp
        )
add_custom_target(rotate-image_run
        COMMAND rotate-image
        )

add_executable(search-a-2d-matrix
        search-a-2d-matrix.cpp
        )
add_custom_target(search-a-2d-matrix_run
        COMMAND search-a-2d-matrix
        )

add_executable(search-a-2d-matrix-ii
        search-a-2d-matrix-ii.cpp
        )
add_custom_target(search-a-2d-matrix-ii_run
        COMMAND search-a-2d-matrix-ii
        )

add_executable(sparse-matrix-multiplication
        sparse-matrix-multiplication.cpp
        )
add_custom_target(sparse-matrix-multiplication_run
        COMMAND sparse-matrix-multiplication
        )

add_executable(triggering_run_matrix
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_matrix
        brick-wall_run
        diagonal-traverse_run
        escape-the-ghosts_run
        island-perimeter_run
        lonely-pixel-i_run
        lonely-pixel-ii_run
        number-of-corner-rectangles_run
        rotate-image_run
        search-a-2d-matrix_run
        search-a-2d-matrix-ii_run
        sparse-matrix-multiplication_run
        )
