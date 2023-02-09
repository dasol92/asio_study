set(Boost_ROOT "C:/Users/zooca/workdir/Boost_v1.64")
set(Boost_LIBRARY_DIR ${Boost_ROOT}/lib)
set(Boost_INCLUDE_DIR ${Boost_ROOT}/include/boost-1_64)
set(Boost_LIBRARIES "")
list(APPEND Boost_LIBRARIES 
	${Boost_LIBRARY_DIR}/libboost_atomic-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_bzip2-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_chrono-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_container-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_context-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_coroutine-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_date_time-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_exception-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_fiber-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_filesystem-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_graph_parallel-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_graph-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_iostreams-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_locale-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_log_setup-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_log-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_c99-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_c99f-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_c99l-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_tr1-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_tr1f-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_math_tr1l-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_mpi-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_numpy-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_numpy3-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_prg_exec_monitor-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_program_options-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_python-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_python3-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_random-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_regex-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_serialization-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_signals-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_system-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_test_exec_monitor-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_thread-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_timer-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_type_erasure-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_unit_test_framework-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_wave-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_wserialization-vc141-mt-1_64.lib
	${Boost_LIBRARY_DIR}/libboost_zlib-vc141-mt-1_64.lib
)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
link_libraries(${Boost_LIBRARIES})