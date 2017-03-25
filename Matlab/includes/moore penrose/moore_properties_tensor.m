function fulfilled = moore_properties_tensor(A,A_moore,order)

% This function should check the 4 Moore Penrose Inverse Properties
% 1. A * A_moore * A = A
% 2. A_moore * A * A_moore = A_moore
% 3. (A * A_moore )^*  = A * A_moore
% 4. (A_moore * A)^* = A_moore * A
% For more Information check: de.wikipedia.org/wiki/Pseudoinverse#Die_Moore-Penrose-Inverse

if( ttp(A,ttp(A_moore,A)) <= (A+0.0000000001))
    if((ttp(A,ttp(A_moore,A))) >= (A-0.0000000001))
        if((ttp(A_moore,ttp(A,A_moore)) <= A_moore+0.0000000001))
            if(ttp(A_moore,ttp(A,A_moore)) >= A_moore-0.0000000001)
                if( transpose_(ttp(A,A_moore),order) <= ttp(A,A_moore)+0.0000000001 )
                    if( transpose_(ttp(A,A_moore),order) >= ttp(A,A_moore)-0.0000000001 )
                        if( transpose_(ttp(A_moore,A),order) <= ttp(A_moore,A)+0.0000000001)
                            if( transpose_(ttp(A_moore,A),order)>= ttp(A_moore,A)-0.0000000001)
                                fulfilled=1;
                            else
                                fulfilled=0;
                            end
                        else
                            fulfilled=0;
                        end
                    else
                        fulfilled=0;
                    end
                else
                    fulfilled=0;
                end
            else
                fulfilled=0;
            end
        else
            fulfilled=0;
        end
    else
        fulfilled=0;
    end
else
    fulfilled=0;
end

end