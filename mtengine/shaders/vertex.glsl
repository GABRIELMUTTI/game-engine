#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform int phong;

out vec3 normal;
out vec4 vertexWorldPosition;


void main()
{
    normal = aNormal;
    vertexWorldPosition = model * vec4(aPos, 1.0);

    gl_Position = projection * view * vertexWorldPosition;

    if (phong == 0)
    {
        vec3 n = normalize(normal);
        vec4 origin = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        vec4 cameraWorldPosition = inverse(view) * origin ;

        vec3 kd = vec3(1, 0.0, 0.0);
        vec3 ks = vec3(0, 0.0, 1.0);
        vec3 I = vec3(1, 0, 1);    
        float q = 0;
        
        vec3 l = normalize(vec3(0.0, 0.3, 0.3));
        vec3 r = -l + (2 * n * (dot(n, l)));
        vec3 v = normalize(cameraWorldPosition - vertexWorldPosition).xyz;

        vec3 lambert = kd * I * max(0, dot(n, l));
        vec3 phong = ks * I * pow(max(0, dot(r, v)), q);

        vec4 color = vec4(lambert + phong, 1.0);
        normal = color.xyz;
    }
    
    
}