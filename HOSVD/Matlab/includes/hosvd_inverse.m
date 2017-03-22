function TENSOR_inverse = hosvd_inverse(S,V_tensor)

    % Compute singular value decomposition for the mode-k flattenings and
    % store U and V.
    S_inverse = S.^(-1);
    
    
    % Compute core tensor S
    for k=1:4
        S_inverse = nmodeproduct(S_inverse,V_tensor(:,:,k),k);
    end
    
    TENSOR_inverse = S_inverse;
    
    % Transform cell Tensor to matrix Tensor

  
end