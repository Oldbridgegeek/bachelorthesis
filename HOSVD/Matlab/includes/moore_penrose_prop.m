% This function should check the 4 Moore Penrose Inverse Properties
% 1. A * A_moore * A = A
% 2. A_moore * A * A_moore = A_moore
% 3. (A * A_moore )^*  = A * A_moore
% 4. (A_moore * A)^* = A_moore * A
% For more Information check: de.wikipedia.org/wiki/Pseudoinverse#Die_Moore-Penrose-Inverse

function fulfilled = moore_penrose_prop(A,A_moore)
    if(A*A_moore*A == A)
        if(A_moore*A*A_moore == A_moore)
            if( transpose(A*A_moore) == A*A_moore )
                if( transpose(A_moore*A) == A_moore * A)
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


end