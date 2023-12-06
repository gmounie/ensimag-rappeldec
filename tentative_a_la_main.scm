;; The ‘guix.scm’ file for Guile, for use by ‘guix shell’.

(use-modules (guix packages)
	     (guix build-system cmake)
	     (guix licenses)
	     (gnu packages base)
	     (gnu packages linux)
	     (guix gexp)
	     )

(package
 (name "today-s-c-for-os")
 (version "2.0.0")
 (source #f)
 ;; (local-file "." "tc4os-checkoput"))
 (build-system cmake-build-system)
 (synopsis "C moderne pour les systèmes d'exploitation")
 (description
  "Exercises travaillant quelques notions utiles de C (dernier standard)
pour la programmation système")
 (home-page "https://github.com/mounieg/rappel-de-c")
 (license gpl3+)
 )
