using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerWeapon : MonoBehaviour
{
    public enum Weapon_Type
    {
        RIFLE = 1,
    }

    public Weapon_Type weaponType;
    [SerializeField]
    private Transform shootingPos;

    /// <summary>
    /// 무기 초기화
    /// </summary>
    /// <param name="type"></param>
    public void Initialize(Weapon_Type type)
    {
        weaponType = type;
    }

    /// <summary>
    /// 무기 사용 메서드
    /// 무기 타입에 따라 총알 속도 및 다르게 설정 되어야 함.
    /// </summary>
    public void UseWeapon()
    {
        switch (weaponType)
        {
            case Weapon_Type.RIFLE:
            {
                var bullet = CreateBullet();
                var rigid = bullet.GetComponent<Rigidbody2D>();
                
                rigid.velocity = -shootingPos.right * 30f;
            }
                break;
        }
    }

    /// <summary>
    /// 총알 생성(이후에 오브젝트 풀링으로 수정되어야 함.)
    /// </summary>
    private GameObject CreateBullet()
    {
        var bullet = Resources.Load<GameObject>("Prefabs/bullet");
        return Instantiate(bullet, shootingPos.position, shootingPos.rotation);
    }
}