#include "mtgraphics/graphic/ShaderProgram.hpp"

namespace mtgraphics
{
    ShaderProgram::ShaderProgram() 
    {
        programId = 0;
    }

    void ShaderProgram::createProgram()
    {
        programId = glCreateProgram();
    }
    
    void ShaderProgram::loadShader(GLenum shaderType, const GLchar* filepath)
    {
        std::ifstream file;
        file.open(filepath, std::ios::in);

        if (file.is_open())
        {
            std::stringstream contentStream;
            contentStream << file.rdbuf();

            std::string stringSource = contentStream.str();
            const GLchar* source = stringSource.c_str();

            // Create && Compile.
            int shader = glCreateShader(shaderType);
            glShaderSource(shader, 1, &source, NULL);
            glCompileShader(shader);
            checkErrors(shader, GL_COMPILE_STATUS, filepath);
            
            // Attach && Link.
            glAttachShader(programId, shader);
            glLinkProgram(programId);
            checkErrors(programId, GL_LINK_STATUS, filepath);

            glDeleteShader(shader);

            file.close();
        }
        else
        {
            std::cout << "Fatal Error: Couldn't open Shader file." << std::endl;
        }
    }

    void ShaderProgram::use()
    {
        glUseProgram(programId);
    }

    void ShaderProgram::checkErrors(GLuint id, GLenum errorType, const GLchar* filepath)
    {
        GLchar infoLog[1024];
        GLint success = true;

        glGetShaderiv(id, errorType, &success);

        if (!success)
        {
            glGetShaderInfoLog(id, 1024, NULL, infoLog);
            std::cout << "Shader error: " << filepath << "\n" << "InfoLog:.\n" << infoLog << std::endl;
        }
    }

    void ShaderProgram::setMat4(const GLchar* uniformName, glm::mat4 matrix)
    {
        GLuint uniformLocation = glGetUniformLocation(programId, uniformName);
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void ShaderProgram::setInt(const GLchar* uniformName, GLint value)
    {
        GLuint uniformLocation = glGetUniformLocation(programId, uniformName);
        glUniform1i(uniformLocation, value);
    }
}
