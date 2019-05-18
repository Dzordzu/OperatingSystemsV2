cmake_minimum_required 	( VERSION 3.1 )
PROJECT ( OperatingSystems
		VERSION		2.0.0
		LANGUAGES	CXX
		DESCRIPTION	"Operating systems simulations - crossplatform API"
	)

add_executable ( OperatingSystemsSimulator
			include/OperatingSystems/Simulator/Main.cpp
			src/Simulator/ProcessorInfo.cpp
	#		src/Simulator/Visual.cpp
	#		src/Simulator/API.cpp
	#		src/Simulator/
	)

add_library ( OperatingSystems
			src/Processor/Process.cpp
			src/Processor/Processor.cpp
			src/Processor/Frame.cpp
			src/Processor/Page.cpp

			src/Algorithms/FrameAllocation/Algorithm.cpp
			src/Algorithms/FrameAllocation/Equal.cpp
			src/Algorithms/FrameAllocation/Proportional.cpp
		    src/Algorithms/FrameAllocation/WorkingSet.cpp
			src/Algorithms/FrameAllocation/ErrorsControlling.cpp

			src/Algorithms/PageReplacement/Algorithm.cpp
			src/Algorithms/PageReplacement/LRU.cpp

		)

target_link_libraries(OperatingSystemsSimulator
		PUBLIC OperatingSystems)

set_target_properties ( OperatingSystems
	PROPERTIES
		LINKER_LANGUAGE	CXX
		CXX_STANDARD	14
	)

target_compile_features ( OperatingSystems
		INTERFACE
	 		cxx_auto_type
			cxx_final
			cxx_nullptr
			cxx_override
		PRIVATE
			cxx_std_14	
	)

target_include_directories ( OperatingSystems 
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
	)	


