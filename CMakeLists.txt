cmake_minimum_required(VERSION 3.20)

project(EnsimagRappelDeC)
enable_testing()
set(CMAKE_BUILD_TYPE Debug)

# alternative: add to the two debug flags: -fsanitize=address -fanalyzer
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wconversion -std=gnu18")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wconversion -std=gnu++17")

#########
# Gestion des logins
#########
# Vous devez editer la ligne suivante pour y mettre votre login. C'est
# inutile pour le rappel de C, mais vous ferez la même chose pour
# l'examen
#########
set(LOGINS petrot)

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

add_executable(flottants src/flottants.c src/abmc.c)

add_executable(fqsort src/fqsort.c)
target_link_libraries(fqsort m)

# bug demonstration programs
add_executable(bug_assert src/bugs/bug_assert.c)
add_executable(bug_doublefree src/bugs/bug_doublefree.c)
add_executable(bug_stackallocthenfree src/bugs/bug_stackallocthenfree.c)
add_executable(bug_stackoverflow src/bugs/bug_stackoverflow.c)
add_executable(bug_overreadheap_tiny src/bugs/bug_overreadheap_tiny.c)
add_executable(bug_overwriteheap_tiny src/bugs/bug_overwriteheap_tiny.c)
add_executable(bug_overwriteheap_large src/bugs/bug_overwriteheap_large.c)
add_executable(bug_allocinstack src/bugs/bug_allocinstack.c)
add_executable(bug_loop src/bugs/bug_loop.c)

##
# Test program
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
