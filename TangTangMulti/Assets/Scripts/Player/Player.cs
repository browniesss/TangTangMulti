using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int moveSpeed = 10;

    private Animator animator;

    private Vector3 movePos;

    [SerializeField]
    private PlayerWeapon weapon;
    
    private void Start()
    {
        Initialize();

        StartCoroutine(CoShoot());
    }

    private IEnumerator CoShoot()
    {
        while (true)
        {
            yield return new WaitForSeconds(0.5f);
            
            weapon.UseWeapon();
        }
    }

    /// <summary>
    /// 플레이어 캐릭터 초기화
    /// </summary>
    private void Initialize()
    {
        animator = GetComponent<Animator>();
        
        movePos = new Vector3();

        weapon.Initialize(PlayerWeapon.Weapon_Type.RIFLE);
    }

    /// <summary>
    /// 플레이어 캐릭터 이동
    /// </summary>
    private void Move()
    {
        movePos = Vector3.zero;
        
        // 방향 입력 받기
        float horizontalInput = Input.GetAxisRaw("Horizontal");
        float verticalInput = Input.GetAxisRaw("Vertical");

        // 이동 벡터 계산
        movePos.x = horizontalInput;
        movePos.y = verticalInput;

        // 이동 벡터가 0이 아닌 경우에만 방향을 바라보도록 설정
        if (movePos != Vector3.zero)
        {
            // 현재 위치에서 목표 방향을 바라보도록 회전
            transform.rotation = Quaternion.LookRotation(Vector3.forward, -movePos.normalized);
        }

        // 이동
        transform.position += (movePos * moveSpeed * Time.deltaTime);
    }
    
    /// <summary>
    /// 플레이어 캐릭터 애니메이션
    /// </summary>
    /// <param name="isVertical">위 아래 이동 수치</param>
    private void SetAnimation(float isVertical)
    {
        animator.SetFloat("verticalValue", isVertical);
    }

    private void Update()
    {
        Move();
    }
}
