﻿using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Dispatch.Model.Models
{
    /// <summary>
    /// quản lý quyền nào thuộc nhóm nào
    /// </summary>
    [Table("ApplicationRoleGroups")]
    public class ApplicationRoleGroup
    {
        [Key]
        [Column(Order = 1)]
        public int GroupId { get; set; }

        [StringLength(128)]
        [Key]
        [Column(Order = 2)]
        public string RoleId { get; set; }

        [ForeignKey("RoleId")]
        public virtual ApplicationRole ApplicationRole { get; set; }

        [ForeignKey("GroupId")]
        public virtual ApplicationGroup ApplicationGroup { get; set; }
    }
}