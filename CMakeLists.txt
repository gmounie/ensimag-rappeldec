cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(EnsimagRappelDeC)
enable_testing()
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wconversion -std=gnu11 -fsanitize-address-use-after-scope")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wconversion -std=gnu++11 -fsanitize-address-use-after-scope")


#########
# Gestion des logins
#########
# Vous devez editer la ligne suivante pour y mettre votre login. C'est
# inutile pour le rappel de C, mais vous ferez la même chose pour
# l'examen
#########
set(LOGINS login1)

if (LOGINS MATCHES "login1")
  message(FATAL_ERROR "** ERREUR / ERROR **: Vous devez modifier CMakeLists.txt pour remplacer login1 par votre login / Substitute login1 with your own login in CMakeLists.txt")
endif()



##
# Si vous utilisez d'autres fichiers .c, en plus de ceux listés,
# il faut les ajouter ici
##
add_executable(listechainee src/listechainee.c)

add_library(ensigc SHARED src/elempool.c src/bitset1000.cpp)
add_executable(ensitestgc tests/gctests.c tests/test0.c tests/test1.c tests/test2.c tests/test3.c tests/test4.c)
target_link_libraries(ensitestgc ensigc)

add_executable(binaires src/binaires.c)

add_executable(hello src/hello.c)
add_executable(flottants src/flottants.c)

add_executable(fqsort src/fqsort.c)
target_link_libraries(fqsort m)

###
# Ensimag CentOS 6: utilisation du compilateur installé pour Ada,
# beaucoup plus récent.
##
if(EXISTS /opt/gnat/bin/g++)
  set(CMAKE_CXX_COMPILER /opt/gnat/bin/g++)
endif(EXISTS /opt/gnat/bin/g++)
if(EXISTS /opt/gnat/bin/gcc)
  set(CMAKE_C_COMPILER /opt/gnat/bin/gcc)
endif(EXISTS /opt/gnat/bin/gcc)

##
# Programme de test
##
add_test(ListeChainee ${CMAKE_BINARY_DIR}/listechainee)
add_test(valgrindListeChainee valgrind ${CMAKE_BINARY_DIR}/listechainee)

add_test(GC ${CMAKE_BINARY_DIR}/ensitestgc --all)
add_test(ValgrindGC valgrind ${CMAKE_BINARY_DIR}/ensitestgc --all)

add_test(Binaire ${CMAKE_BINARY_DIR}/../tests/binairestests.rb)

add_test(Hello ${CMAKE_BINARY_DIR}/../tests/hellotests.rb)

add_test(Flottants ${CMAKE_BINARY_DIR}/../tests/flottantstests.rb)

add_test(TriComplexe ${CMAKE_BINARY_DIR}/fqsort)
add_test(valgrindTriComplexe valgrind ${CMAKE_BINARY_DIR}/fqsort)

# version verbose de tous les tests
add_custom_target(check ctest -V)
