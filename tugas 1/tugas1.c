#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Untuk fork(), getpid(), getppid()
#include <sys/types.h> // Untuk pid_t

int main(int argc, char *argv[]) {
    // Memastikan argumen input jumlah child process diberikan
    if (argc != 2) {
        printf("Usage: %s <number_of_child_processes>\n", argv[0]);
        return 1; // Mengembalikan error jika argumen salah
    }

    // Mengambil jumlah child process dari command line
    int num_children = atoi(argv[1]); // Konversi dari string ke integer

    if (num_children <= 0) {
        printf("Error: Please provide a positive integer for the number of child processes.\n");
        return 1; // Error jika input tidak valid
    }

    printf("Parent process PID: %d\n", getpid());

    // Membuat sejumlah child process
    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork(); // Membuat proses baru

        if (pid < 0) {
            // Jika fork() gagal
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            // Kode ini dijalankan oleh child process
            printf("Child %d created with PID: %d, Parent PID: %d\n", i + 1, getpid(), getppid());
            exit(0); // Child process selesai
        } else {
            // Kode ini dijalankan oleh parent process
            // Parent akan melanjutkan ke loop berikutnya untuk membuat child baru
        }
    }

    // Parent process menunggu semua child selesai
    for (int i = 0; i < num_children; i++) {
        wait(NULL); // Tunggu child process selesai
    }

    printf("All child processes have completed.\n");

    return 0;
}
