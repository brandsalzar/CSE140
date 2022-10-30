void dgemm( int m, int n, float *A, float *C ){
//  //FILL-IN 
  int i;                                                        //i declared outside of loops so that we can utilize in both loops

  for(i = 0; i < m - 3; i += 4)                                 //row
    for(int k = 0; k < n; k++)                                  //column 
      for(int j = 0; j < m; j++){                               //basically done to do the transposed version 

        C[i + m * j]     += A[i + k * m] * A[j + k * m];        //i+k is A j+k is A' original iteration

        C[(i + 1) + m * j] += A[(i + 1) + k * m] * A[j + k * m];//First  loop unrolling iteration
        C[(i + 2) + m * j] += A[(i + 2) + k * m] * A[j + k * m];//Second loop unrolling iteration
        C[(i + 3) + m * j] += A[(i + 3) + k * m] * A[j + k * m];//Third  loop unrolling iteration*/
  }//end forloops
   
  for(i; i < m; i++)                                            //picks up from where you left off
    for( int k = 0; k < n; k++) 
      for( int j = 0; j < m; j++) 
        C[i + m * j] += A[i + k * m] * A[j + k * m];

 }//END LOOP UNROLLING

// *************************************************************************************************************************************

//void dgemm( int m, int n, float *A, float *C ){//reordering
//  for( int k = 0; k < n; k++ )                  //reordered this k fom i
//    for( int i = 0; i < m; i++ )                 //reordered this i from k
//      for( int j = 0; j < m; j++ ) 
//        C[i+j*m] += A[i+k*m] * A[j+k*m];
// }//END REORDERING

// *************************************************************************************************************************************

//void dgemm( int m, int n, float *A, float *C ){// tyling
//// FILL-IN 
//// m corresponds to row 
//// n corresponds to columns
//// A and C are single matrices
//// Blocking/Tiling
//// Blocking proved to be faster than naive
//
//  int i, j, k, l;
//  float B; //not a matrix, this is for summing 
//  int blockSize = n - (n % 4);
//
//  for (i = 0; i < blockSize; i += 4) {                    // this strides through the block size or hits
//     for (j = 0; j < m; j++) {                            // loops through the rows (m)
//         for (k = 0; k < m; k++) {                        // loops through the rows (m)
//            float B = C[j + k * m];                       // perform matrix multplication (Ask daniel about this tomorrow)
//            for (l= i; l < i + 4; l++) {
//                B += A[j + l * m] * A[k + l * m];
//            }
//            C[j + k * m] = B;
//          }
//      }
//  }
//
//  for (k = blockSize; k < n; k++) {                        //going through the colum from the block size
//     for(i = 0; i < m; i++) {                              // iterating through row
//         for(j = 0; j < m; j++) {                          //iterating through row
//             C[i + j * m] += A[i + k * m] * A[j + k * m];  //summing A matrix into the C matrix
//         }
//     }
//  }
//  
//} //End TILING/BLOCKING