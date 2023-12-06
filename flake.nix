{
  description = "Shell";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in
      with pkgs;
      {
        devShells.default = mkShell.override { stdenv = pkgs.clangStdenv; } {
          packages = [
            clang_16
            cmake
            gdb
            valgrind
            doxygen
            clang-tools
            gtest
          ];
        };
      }
    );
}
