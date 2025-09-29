#include "Serialization.hpp"

int main ()
{
    Data* data = new Data();
    data->n = 42;
    data->s = "Hello, World!";
    data->f = 3.14f;

    std::cout << "Original Data:" << std::endl;
    std::cout << "n: " << data->n << ", s: " << data->s << ", f: " << data->f << std::endl;

    uintptr_t raw = Serialization::serialize(data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serialization::deserialize(raw);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "n: " << deserializedData->n << ", s: " << deserializedData->s << ", f: " << deserializedData->f << std::endl;

    delete data;
    return 0;
}