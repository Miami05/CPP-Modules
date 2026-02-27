#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

static void printData(const Data *d, const char *label) {
    std::cout << label << ":\n";
    if (!d) {
        std::cout << "   (null)\n";
        return;
    }
    std::cout << "  addr   " << d << "\n";
    std::cout << "  id    = " << d->id << "\n";
    std::cout << "  name  = " << d->name << "\n";
    std::cout << "  score = " << d->score << "\n";
}

int main() {
    Data original(42, "Umbrella", 99.5);
    Data *p1 = &original;
    uintptr_t raw = Serializer::serialize(p1);
    Data *p2 = Serializer::deserialize(raw);
    printData(p1, "Original pointer");
    std::cout << "Serialized raw value: " << raw << "\n";
    printData(p2, "Deserialized pointer");
    std::cout << "\nPointer equality check: "
        << (p1 == p2 ? "OK (same address)" : "FAIL (different address)") << "\n";
    Data *nullPtr = 0;
    uintptr_t rawNull = Serializer::serialize(nullPtr);
    Data *backNull = Serializer::deserialize(rawNull);
    std::cout << "\n--- Null edge case ---\n";
    std::cout << "rawNull = " << rawNull << "\n";
    std::cout << "backNull = " << backNull << "\n";
    std::cout << "null equality check: "<< (nullPtr == backNull ? "OK" : "FAIL") << "\n";
    return 0;
}
