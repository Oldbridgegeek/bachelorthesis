function [U_tensor,S_tensor,V_tensor] = hosvd(TENSOR)

    for k=1:4
        TENSOR_flattened = flatten(TENSOR,k)
        [U,E,V] = svd(TENSOR_flattened);
        U_tensor(:,:,k) = U;
        V_tensor(:,:,k) = V;
    end
    
   


end