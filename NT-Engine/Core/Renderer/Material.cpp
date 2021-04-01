#include "Material.h"

NT::Material::Material(glm::vec3 albedo, glm::vec3 diffuse, glm::vec3 specular, float shininess)
	: albedo(albedo), diffuse(diffuse), specular(specular), shininess(shininess)
{
}
