cmake_minimum_required(VERSION 3.20)

project(EnsimagRappelDeC)
enable_testing()
set(CMAKE_BUILD_TYPE Debug)
# affiche les commandes du makefile par défaut (exposer les étudiants à ce que fait le makefile pour eux)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

# alternative: use ASan memory checker. Incompatible with valgrind: -fsanitize=address
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -fanalyzer -Wconversion")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fanalyzer -Wconversion")

#########
# Gestion des auteurs du TP
#########
if (EXISTS ${CMAKE_SOURCE_DIR}/AUTHORS)
  message(STATUS "Les auteurs du TP incrits dans AUTHORS sont / AUTHORS are:")
  execute_process (COMMAND cat AUTHORS WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
else()
  message(FATAL_ERROR "** ERREUR / ERROR **: Vous devez mettre vos prénoms, noms et login dans un fichier nommé 'AUTHORS' à la racine du projet / Add an 'AUTHORS' file with all authors' name, firstname and login at the project root; Fichier manquant/missing file: "  ${CMAKE_SOURCE_DIR}/AUTHORS)
endif()

##
# Si vous utilisez d'autres fichiers .c, en plus de ceux listés,
# il faudra les ajouter ici
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

# bug demonstration programs
add_executable(bug_assert bug-training/bug_assert.c)
add_executable(bug_doublefree bug-training//bug_doublefree.c)
add_executable(bug_stackallocthenfree bug-training//bug_stackallocthenfree.c)
add_executable(bug_stackoverflow bug-training/bug_stackoverflow.c)
add_executable(bug_overreadheap_tiny bug-training/bug_overreadheap_tiny.c)
add_executable(bug_overwriteheap_tiny bug-training/bug_overwriteheap_tiny.c)
add_executable(bug_overwriteheap_large bug-training/bug_overwriteheap_large.c)
add_executable(bug_allocinstack bug-training/bug_allocinstack.c)
add_executable(bug_loop bug-training/bug_loop.c)

##
# Test programs
##
add_test(ListeChainee ${CMAKE_BINARY_DIR}/listechainee)
add_test(valgrindListeChainee valgrind ${CMAKE_BINARY_DIR}/listechainee)

add_test(GC ${CMAKE_BINARY_DIR}/ensitestgc --all)
add_test(ValgrindGC valgrind ${CMAKE_BINARY_DIR}/ensitestgc --all)

add_test(Binaire ${CMAKE_SOURCE_DIR}/tests/binairestests.rb)

add_test(Hello ${CMAKE_SOURCE_DIR}/tests/hellotests.rb)

add_test(Flottants ${CMAKE_SOURCE_DIR}/tests/flottantstests.rb)

add_test(TriComplexe ${CMAKE_BINARY_DIR}/fqsort)
add_test(valgrindTriComplexe valgrind ${CMAKE_BINARY_DIR}/fqsort)

# version verbose de tous les tests
add_custom_target(check ctest -V)
