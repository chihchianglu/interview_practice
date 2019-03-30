add_executable(alien-dictionary
        alien-dictionary.cpp
        )
add_custom_target(alien-dictionary_run
        COMMAND alien-dictionary
        )

add_executable(alien-dictionary-ii
        alien-dictionary-ii.cpp
        )
add_custom_target(alien-dictionary-ii_run
        COMMAND alien-dictionary-ii
        )

add_executable(cheapest-flights-within-k-stops
        cheapest-flights-within-k-stops.cpp
        )
add_custom_target(cheapest-flights-within-k-stops_run
        COMMAND cheapest-flights-within-k-stops
        )

add_executable(clone-graph
        clone-graph.cpp
        )
add_custom_target(clone-graph_run
        COMMAND clone-graph
        )

add_executable(course-schedule
        course-schedule.cpp
        )
add_custom_target(course-schedule_run
        COMMAND course-schedule
        )

add_executable(course-schedule-ii
        course-schedule-ii.cpp
        )
add_custom_target(course-schedule-ii_run
        COMMAND course-schedule-ii
        )

add_executable(evaluate-division
        evaluate-division.cpp
        )
add_custom_target(evaluate-division_run
        COMMAND evaluate-division
        )

add_executable(graph-valid-tree
        graph-valid-tree.cpp
        )
add_custom_target(graph-valid-tree_run
        COMMAND graph-valid-tree
        )

add_executable(is-graph-bipartite
        is-graph-bipartite.cpp
        )
add_custom_target(is-graph-bipartite_run
        COMMAND is-graph-bipartite
        )

add_executable(minimum-height-trees
        minimum-height-trees.cpp
        )
add_custom_target(minimum-height-trees_run
        COMMAND minimum-height-trees
        )

add_executable(number-of-connected-components-in-an-undirected-graph
        number-of-connected-components-in-an-undirected-graph.cpp
        )
add_custom_target(number-of-connected-components-in-an-undirected-graph_run
        COMMAND number-of-connected-components-in-an-undirected-graph
        )

add_executable(possible-bipartition
        possible-bipartition.cpp
        )
add_custom_target(possible-bipartition_run
        COMMAND possible-bipartition
        )

add_executable(reconstruct-itinerary
        reconstruct-itinerary.cpp
        )
add_custom_target(reconstruct-itinerary_run
        COMMAND reconstruct-itinerary
        )

add_executable(redundant-connection
        redundant-connection.cpp
        )
add_custom_target(redundant-connection_run
        COMMAND redundant-connection
        )

add_executable(redundant-connection-ii
        redundant-connection-ii.cpp
        )
add_custom_target(redundant-connection-ii_run
        COMMAND redundant-connection-ii
        )

add_executable(sequence-reconstruction
        sequence-reconstruction.cpp
        )
add_custom_target(sequence-reconstruction_run
        COMMAND sequence-reconstruction
        )

add_executable(triggering_run_graph
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_graph
        alien-dictionary_run
        alien-dictionary-ii_run
        cheapest-flights-within-k-stops_run
        clone-graph_run
        course-schedule_run
        course-schedule-ii_run
        evaluate-division_run
        graph-valid-tree_run
        is-graph-bipartite_run
        minimum-height-trees_run
        number-of-connected-components-in-an-undirected-graph_run
        possible-bipartition_run
        reconstruct-itinerary_run
        redundant-connection_run
        redundant-connection-ii_run
        sequence-reconstruction_run
        )
