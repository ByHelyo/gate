{pkgs ? import <nixpkgs> {} }:

pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
    
    buildInputs = with pkgs; [
      clang-tools
      gnumake
      cmake
      man-pages
      gdb
      valgrind
      doxygen
    ];

    nativeBuildInputs = with pkgs; [
        clang_15
    ];
}
