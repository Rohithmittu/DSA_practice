
// vector<int> chocolateFest(vector<int> choco, int x)
// {
//     // Initialize current sum, minimum length, starting index for answer
//     int n = choco.size();
//     int min_len = n;
//     int start_index = 0;



//     for (int i = 0; i < n; i++)
//     {
//         int curr_sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             curr_sum = curr_sum + choco[j];
//             if (curr_sum > x && (j - i + 1) < min_len)
//             {
//                 min_len = j - i + 1;
//                 start_index = i;
//             }
//         }
//     }

//     vector<int> result;

//     for (int i = start_index; i < start_index + min_len; i++)
//     {
//         result.push_back(choco[i]);
//     }
    
//     return result;
// }


// ****************************************************************************************************************