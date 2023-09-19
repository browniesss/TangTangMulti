using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int moveSpeed = 10;
    void Start()
    {
        
    }

    private void Move()
    {
        var movePos = Vector3.zero;
        
        movePos.x += Input.GetAxisRaw("Horizontal");
        movePos.y += Input.GetAxisRaw("Vertical");

        transform.position += movePos * moveSpeed * Time.deltaTime;
    }

    void Update()
    {
        Move();
    }
}
