#include "Renderer.h"
#include "utility.h"

#include <iostream>

// Helper function: Convert free board positions to whitespace
static char ZeroToSpace(char c) {
    return c != 0 ? c : ' ';
}

// Print board vector to screen (vector of chars)
void Renderer::RenderBoard(const std::vector<char>& v)  {
    auto i = 0;
    PrintMessage("=======\n");
    for (auto x = 0; x < 3; ++x) {
        PrintMessage('|', ZeroToSpace(v[i++]));
        PrintMessage('|', ZeroToSpace(v[i++]));
        PrintMessage('|', ZeroToSpace(v[i++]), "|\n");
    }
    PrintMessage("=======\n");
}
