#define MAX_TASKS 5

typedef void (*TaskFunction_t)(void);

typedef struct {
    TaskFunction_t taskFunction;
    uint8_t periodicity; // Cada cuántos ticks ejecutar
    uint8_t counter;
} Task;

Task taskList[MAX_TASKS];

void scheduler_run() {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskList[i].taskFunction != NULL) {
            if (taskList[i].counter == 0) {
                taskList[i].taskFunction();
                taskList[i].counter = taskList[i].periodicity - 1;
            } else {
                taskList[i].counter--;
            }
        }
    }
}
