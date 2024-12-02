1. Kompilasi Program: Gunakan compiler GCC untuk mengompilasi program:

`gcc -o create_children create_children.c`

2. Eksekusi Program: Jalankan program dengan memberikan jumlah child process yang ingin dibuat: (Contoh: Membuat 5 child processes)

`./create_children 5`


**penjelasan program**

1. Argumen Command Line:

Argumen pertama (argv[0]) adalah nama program.
Argumen kedua (argv[1]) adalah jumlah child processes yang dimasukkan pengguna.

2. Fungsi fork():

fork() membuat proses baru.
pid == 0: Menandakan kode dijalankan oleh child process.
pid > 0: Menandakan kode dijalankan oleh parent process.

3. Proses Parent Menunggu:

Setelah semua child processes dibuat, parent process menunggu dengan wait(NULL) untuk memastikan child process selesai.
Output: Program mencetak PID dari setiap child process beserta PID dari parent process.



