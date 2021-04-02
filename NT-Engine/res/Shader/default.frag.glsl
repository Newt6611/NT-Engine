#version 450 core


in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;



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

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;

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

	FragColor = texture(texture_diffuse1, TexCoords);
}