#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in vec3 tangent;
layout(location = 4) in vec3 bitangent;

out VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	mat3 TBN;
} vs_out;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vs_out.Normal = normalize(normal);
	vs_out.FragPos = vec3(model * vec4(position, 1));
	vs_out.TexCoords = texCoords;

	vec3 N = normalize((model * vec4(normal, 0)).xyz);
	vec3 T = normalize((model*vec4(tangent,0)).xyz);
	T = normalize(T - dot(T, N) * N);
	vec3 B = cross(T, N);
	vs_out.TBN = mat3(T, B, N);

	gl_Position = projection * view * model * vec4(position, 1);
}