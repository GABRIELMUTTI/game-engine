#pragma once

#include "mtgraphics/engine/GLInclude.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

namespace mtgraphics
{
    class ShaderProgram
    {
    private:
	GLuint programId;

	void checkErrors(GLuint shader, GLenum errorType, const GLchar* filepath);

    public:
	ShaderProgram();

	void createProgram();
	void loadShader(GLenum shaderType, const GLchar* filepath);
	void use();
            
	void setMat4(const GLchar* uniformName, glm::mat4 matrix);
	void setInt(const GLchar* uniformName, GLint value);
    };
}
