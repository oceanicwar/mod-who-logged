CU_SET_PATH("CMAKE_WHO_LOGGED_DIR" "${CMAKE_CURRENT_LIST_DIR}")

AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/who_logged.cpp")

AC_ADD_SCRIPT_LOADER("WhoLogged"      "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/who-logged.conf.dist")

message("-- WhoLogged CONFIGURED --")
