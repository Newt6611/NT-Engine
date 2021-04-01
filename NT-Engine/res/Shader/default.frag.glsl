#version 450 core

struct Material {
	vec3 albedo;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};


uniform Material material;

uniform vec3 viewPos;

uniform vec3 lightColor;
uniform vec3 lightDir;

in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
	// Directional Light Test
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 lightRefl = normalize(reflect(-lightDir, Normal));
	
	vec3 ambient = material.albedo * lightColor;

	float diff = max(dot(Normal, normalize(lightDir)), 0);
	vec3 diffuse = diff * material.diffuse * lightColor;

	float spec = pow(max(dot(viewDir, lightRefl), 0), material.shininess);
	vec3 specular = spec * material.specular * lightColor;

	vec4 result = vec4(ambient + diffuse + specular, 1);

	//FragColor = vec4(Normal,1);
	FragColor = result;
}