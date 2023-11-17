#pragma once

#include <glm/glm.hpp>
#include "Uniform.h"
#include "Color.h"
#include "Fragment.h"
#include "Vertex.h"

Vertex vertexShader(const Vertex& vertex, const Uniforms& uniforms);
Fragment fragmentShader(const Fragment& fragment);
Fragment testFragmentShader(const Fragment& fragment);
Fragment shipFragmentShader(const Fragment& fragment);