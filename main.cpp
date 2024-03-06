#include <iostream>
#include <vector>

const int PHYSICAL_MEMORY_SIZE = 1 * 1024 * 1024 * 1024; // 1GB
const long VIRTUAL_MEMORY_SIZE = 4 * 1024 * 1024 * 1024; // 4GB
const int PAGE_SIZE = 4906;

struct Process {
    size_t memoryRequirement;
};

size_t calculatePagesNeeded(size_t memoryRequirement) {
    return (memoryRequirement + PAGE_SIZE - 1) / PAGE_SIZE;
}

int main() {
    // Example: Creating a process requiring 1MB of memory
    Process myProcess{1024 * 1024}; // 1MB
    size_t pagesNeeded = calculatePagesNeeded(myProcess.memoryRequirement);
    std::cout << "Pages needed for the process: " << pagesNeeded << std::endl;

    // Further logic to allocate these pages...
    return 0;
}
