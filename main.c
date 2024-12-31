#include <stdio.h>
#include "lsm_tree.h"
#include "cli.h"

int main() {
    LSMTree* lsm = lsm_tree_init();
    if (!lsm) {
        fprintf(stderr, "Failed to initialize LSM Tree.\n");
        return 1;
    }

    run_cli(lsm);
    lsm_tree_destroy(lsm);
    return 0;
}