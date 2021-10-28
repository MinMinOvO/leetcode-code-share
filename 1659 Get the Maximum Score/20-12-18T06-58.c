#define MODEL (1E9 + 7)

int maxSum(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int p1 = nums1Size-1, p2 = nums2Size-1;
    int sum1 = 0, sum2 = 0;
    int modelTimes1 = 0, modelTimes2 = 0;
    while(true){
        if(nums1[p1] > nums2[p2]){
            sum1 += nums1[p1];
            if(sum1 >= MODEL){
                sum1 -= MODEL;
                modelTimes1 += 1;
            }
            p1 -= 1;
            if(p1 < 0){
                break;
            }
        }else if(nums2[p2] > nums1[p1]){
            sum2 += nums2[p2];
            if(sum2 >= MODEL){
                sum2 -= MODEL;
                modelTimes2 += 1;
            }
            p2 -= 1;
            if(p2 < 0){
                break;
            }
        }else{ // nums1[p1] == nums2[p2]
            if(modelTimes1 > modelTimes2 || (modelTimes1 == modelTimes2 && sum1 > sum2)){
                sum1 += nums1[p1];
                if(sum1 >= MODEL){
                    sum1 -= MODEL;
                    modelTimes1 += 1;
                }
                sum2 = sum1;
                modelTimes2 = modelTimes1;
            }else{
                sum2 += nums1[p1];
                if(sum2 >= MODEL){
                    sum2 -= MODEL;
                    modelTimes2 += 1;
                }
                sum1 = sum2;
                modelTimes1 = modelTimes2;
            }
            p1 -= 1;
            p2 -= 1;
            if(p1 < 0 || p2 < 0){
                break;
            }
        }
    }
    while(p1 >= 0){
        sum1 += nums1[p1];
        if(sum1 >= MODEL){
            sum1 -= MODEL;
            modelTimes1 += 1;
        }
        p1 -= 1;
    }
    while(p2 >= 0){
        sum2 += nums2[p2];
        if(sum2 >= MODEL){
            sum2 -= MODEL;
            modelTimes2 += 1;
        }
        p2 -= 1;
    }
    if(modelTimes1 > modelTimes2 || (modelTimes1 == modelTimes2 && sum1 > sum2)){
        return sum1;
    }else{
        return sum2;
    }
}