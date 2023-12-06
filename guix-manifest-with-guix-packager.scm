(define-module (guix-packager)
  #:use-module (guix)
  #:use-module (guix build-system gnu)
  #:use-module (guix build-system cmake)
  #:use-module (guix git-download)
  #:use-module ((guix licenses) #:prefix license:)
  #:use-module (gnu packages)
  #:use-module (gnu packages bash)
  #:use-module (gnu packages cmake)
  #:use-module (gnu packages ruby)
  #:use-module (gnu packages gcc))

(define-public ensimag-c-for-os
  (package
    (name "ensimag-c-for-os")
    (version "2.0")
    (source
      (origin
        (method git-fetch)
        (uri (git-reference
              (url "git@github.com:gmounie/ensimag-rappeldec.git")
              (recursive? #f)
              (commit "master")))
        (file-name (git-file-name name version))
        (sha256 (base32 "1yndz62drc5vbjqsk15jqwrrlgs16i1yssi7sjh9ad06wx8w2gdl"))))
    (native-inputs
     (list cmake ruby-minitest gcc-13 bash))
    (inputs
     (list bash))
    (build-system cmake-build-system)
    (arguments (list #:configure-flags #~(list "--enable-silent-rules")
                     #:test-target "check"
                     #:tests? #t
                     #:build-type "Debug"))
    (home-page "https://github.com/gmounie/ensimag-rappeldec")
    (synopsis "Training in using modern C for OS lectures and practicals")
    (description "Exercises to train master students to use modern C for OS lectures and practicals")
    (license license:gpl3+)))

;; This allows you to run guix shell -f example.scm.
;; Remove this line if you just want to define a package.
ensimag-c-for-os