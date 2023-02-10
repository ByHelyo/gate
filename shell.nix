{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {

  nativeBuildInputs = with pkgs; [
    clang_15
  ];

  buildInputs = with pkgs; [
    clang-tools
    gnumake
    cmake
    man-pages
    gdb
    valgrind
    doxygen
  ];
}
