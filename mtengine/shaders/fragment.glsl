#version 330 core
out vec4 FragColor;

uniform mat4 view;
uniform int phong;

in vec3 normal;
in vec4 vertexWorldPosition;

void main()
{
    vec4 color;
    
    if (phong == 1)
    {
        vec3 n = normalize(normal);
        vec4 origin = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        vec4 cameraWorldPosition = inverse(view) * origin ;

        vec3 kd = vec3(0.5, 0.3, 0.2);
        vec3 ks = vec3(0.5, 0.5, 0.5);
        vec3 I = vec3(1, 1, 1);    
        float q = 0;
        
        vec3 l = normalize(vec3(0.0, 0.3, 0.3));
        vec3 r = -l + (2 * n * (dot(n, l)));
        vec3 v = normalize(cameraWorldPosition - vertexWorldPosition).xyz;

        vec3 lambert = kd * I * max(0, dot(n, l));
        vec3 phong = ks * I * pow(max(0, dot(r, v)), q);

        color = vec4(lambert + phong, 1.0);
    }
    else
    {
        color = vec4(normal, 1.0);
    }
    

    FragColor = color;
    
} 