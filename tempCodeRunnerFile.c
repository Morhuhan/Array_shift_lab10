    tmp = A[0];  // Cycle shift to the left
    for(int i = 0; i < N-1; ++i)
        A[i] = A[i+1];
    A[N-1] = tmp;
    print_array(A);